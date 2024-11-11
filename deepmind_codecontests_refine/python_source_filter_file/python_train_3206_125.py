
a,b,k = map(int, input().split( ))

a1 = max(a-k,0)
a2 = max(b-(k-a1),0)
print(a1,a2)