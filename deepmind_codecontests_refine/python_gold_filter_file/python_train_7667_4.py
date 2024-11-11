n=int(input())
a=list(input().split())
q=[]
for i in a:
    w=sorted(list(set(list(i))))
    if w not in q:
        q.append(w)

print(len(q))