using Microsoft.AspNetCore.Components;
using Microsoft.JSInterop;

namespace CustomComponent
{
    public partial class Component1 : IAsyncDisposable
    {

        [Inject]
        public IJSRuntime? JSRuntime { get; set; }
        TypeScriptInterop? TSInterop { get; set; } = null!;

        public string Message { get; set; } = "";
        public string thing { get; set; } = "";

        public async Task SayHi()
        {
            string v = await TSInterop.SayHi(Message + thing);
        }

        protected override void OnAfterRender(bool firstRender)
        {
            if (firstRender)
            {
#pragma warning disable CS8604 // Possible null reference argument.
                TSInterop = new TypeScriptInterop(JSRuntime);
#pragma warning restore CS8604 // Possible null reference argument.
            }
        }

        public ValueTask DisposeAsync()
        {
#pragma warning disable CS8600 // Converting null literal or possible null value to non-nullable type.
#pragma warning disable CS8602 // Dereference of a possibly null reference.
            return ((IAsyncDisposable)TSInterop).DisposeAsync();
#pragma warning restore CS8602 // Dereference of a possibly null reference.
#pragma warning restore CS8600 // Converting null literal or possible null value to non-nullable type.
        }
    }
}