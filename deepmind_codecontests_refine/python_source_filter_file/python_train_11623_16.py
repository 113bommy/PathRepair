v1,v2,v3,vm=map(int,input().split())
if vm>2*v3 or 2*vm<v3 or vm>v2:
    print(-1)
else:
    print(2*v1,2*v2,min(2*vm,2*v3))