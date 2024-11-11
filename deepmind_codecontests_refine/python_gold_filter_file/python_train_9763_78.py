a,b,c,k=map(int,input().split())
print(min((a-max(k-a-b,0)),k))