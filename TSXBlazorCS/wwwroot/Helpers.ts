namespace TSXBlazorCS.wwwroot
{
    class Logger 
    {
        public log(text: string)
        {
            console.log(text);
        }
    }

    export function getLogger(): Logger
    {
        return new Logger();
    }
}
