
def issub(x,y):
    index=0
    for counter in x:
        if index < len(y) and counter == y[index]:
            index +=1
    return index == len(y)


s = input()
t = input()
ss=sorted(s)
st=sorted(t)

if ss==st:
    print("array")
elif issub(s,t):
    print("automaton")
elif issub(ss,st):
    print("both")
else:
    print("need tree")