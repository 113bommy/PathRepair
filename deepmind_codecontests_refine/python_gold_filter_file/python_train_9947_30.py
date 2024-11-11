t,s,x=map(int, input().split())
print("NO" if (x-t)%s and (((x-t-1)%s) if x-t-1 else 1) or x<t else "YES")
