using Microsoft.JSInterop;

namespace CustomComponent
{
    // This class provides an example of how JavaScript functionality can be wrapped
    // in a .NET class for easy consumption. The associated JavaScript module is
    // loaded on demand when first needed.
    //
    // This class can be registered as scoped DI service and then injected into Blazor
    // components for use.

    public class TypeScriptInterop : IAsyncDisposable
    {
        private readonly Lazy<Task<IJSObjectReference>> moduleTask;

        public TypeScriptInterop(IJSRuntime jsRuntime)
        {
            moduleTask = new(() => jsRuntime.InvokeAsync<IJSObjectReference>(
                "import", "./_content/CustomComponent/CustomComponent.js").AsTask());
        }

        public async ValueTask<string> Prompt(string message)
        {
            var module = await moduleTask.Value;
            return await module.InvokeAsync<string>("showPrompt", message);
        }

        // thong 1
        public async ValueTask<string> SayHi(string message)
        {
            var js = await GetJS();
            var result = await js.InvokeAsync<string>(message);
            await js.DisposeAsync();
            return result;
        }

        public async Task<IJSObjectReference> GetJS()
        {
            var module = await moduleTask.Value;
            return await module!.InvokeAsync<IJSObjectReference>("GetInstance");
        }

        public async ValueTask DisposeAsync()
        {
            if (moduleTask.IsValueCreated)
            {
                var module = await moduleTask.Value;
                await module.DisposeAsync();
            }
        }
    }
}