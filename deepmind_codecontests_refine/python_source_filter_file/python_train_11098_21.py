def ri(): return int(input())
def rli(): return list(map(int, input().split()))
def ris(): return list(input())
def pli(a): return "".join(list(map(str, a)))
def plis(a): return " ".join(list(map(str, a)))

di = ["v", "<", "^", ">"]
s, e = input().split()
n = ri() % 4
s = di.index(s)
e = di.index(e)
iscw = True
if(n == 0 or n == 2):
    print("undefined")
elif(n == 1):
    if(s-e > 0 or s-e == -3):
        iscw = False
    print("cw" if iscw else "ccw")
else:
    if(e-s > 0 or e-s == -3):
        iscw = False
    print("cw" if iscw else "ccw")