n=int(input())
a=list(input().split())
q=[]
for i in a:
    w=list(set(list(i)))
    if w not in q:
        q.append(w)
print(len(q))