var TSXBlazorCS;
(function (TSXBlazorCS) {
    var wwwroot;
    (function (wwwroot) {
        class Logger {
            log(text) {
                console.log(text);
            }
        }
        function getLogger() {
            return new Logger();
        }
        wwwroot.getLogger = getLogger;
    })(wwwroot = TSXBlazorCS.wwwroot || (TSXBlazorCS.wwwroot = {}));
})(TSXBlazorCS || (TSXBlazorCS = {}));
//# sourceMappingURL=Helpers.js.map