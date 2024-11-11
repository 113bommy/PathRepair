#hanafuda
N,r=(int(i) for i in input().split())
while N!=0 or r!=0:
    H=[int(i+1) for i in range(N)]
    for i in range(r):
        p,c=(int(i) for i in input().split())
        T=[]
 #       print(H)
        for j in range(p-1,p+c-1):
  #          print("T")
            T.append(H[p-1])
            H.pop(p-1)
        H=T+H
    print(H[0])
    N,r=(int(i) for i in input().split())