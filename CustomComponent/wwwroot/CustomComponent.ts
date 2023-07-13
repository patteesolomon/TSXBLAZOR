class Component1
{
    public sayHi(message: string) {
        alert("Component says " + message);
    }

    public THISsuckS(thing: string) {
        alert("Kill me")
    }
}

export function GetInstance() {
    return new Component1();
}