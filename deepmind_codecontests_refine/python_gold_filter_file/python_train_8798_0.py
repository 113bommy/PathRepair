def val(x):
    return x[1]
n = int(input())
chatQ = {}
c = 0
for i in range(1,n+1):
    name = str(input()) 
    if name not in chatQ:
        chatQ[name] = i
    else:
        chatQ[name] = c 
    c = chatQ.get(name) + 1
x = list(chatQ.keys())
y = list(chatQ.values())
z = []
for i in range(len(x)):
    z.append([x[i],y[i]])
z.sort(key=val, reverse=True)
for i in z:
    print(i[0])