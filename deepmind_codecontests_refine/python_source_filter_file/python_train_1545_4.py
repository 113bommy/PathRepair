Ns = [input() for _ in range(int(input()))]
Ms = [input() for _ in range(int(input()))]
l = list(set(Ns))
print(max(0,max((Ns.count(l[i])-Ms.count(l[i]) for i in range(len(l))))))a