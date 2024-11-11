a,b,k=map(int,input().split())
if a>=k:
    print(k-a,b)
else:
    print(0,max(b-(k-a),0))
