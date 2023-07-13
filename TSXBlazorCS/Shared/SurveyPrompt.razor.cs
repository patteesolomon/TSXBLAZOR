namespace TSXBlazorCS.Shared
{
    public partial class SurveyPrompt
    {
    // Demonstrates how a parent component can supply parameters
    [Parameter]
        public string? Title { get; set; }

        [Inject]
        public IJSRuntime JSRuntime { get; set; }

        IJSObjectReference? javascript;

        protected async Task ShowAlert()
        {
            string msg = $"Hello from JavaScript at {DateTime.Now.ToLongTimeString()}";
            await javascript!.InvokeVoidAsync("log", msg);

            string name = await javascript!.InvokeAsync<string>("displayPrompt", "What is your name?");
            await javascript!.InvokeVoidAsync("displayAlert", $"Hello {name}!");
        }

        protected override async Task OnAfterRenderAsync(bool firstRender)
        {
            if (firstRender) 
            {
                /*
                web address goes here 
                 */
                var jsmodule =
                    await JSRuntime.InvokeAsync<IJSObjectReference>("import", "./Shared/SurveyPrompt.razor.js");
                javascript = await jsmodule!.InvokeAsync<IJSObjectReference>("GetInstance");
                // use
                await jsmodule.DisposeAsync();
            }
        }

        public async ValueTask DisposeAsync()
        {
            if(javascript != null)
            {
                await javascript!.DisposeAsync();
            }
        }
    }
}
