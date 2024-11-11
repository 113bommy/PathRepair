def main():
    #部分集合のサイズnの時n+1個の部分集合
    n=int(input())
    if 2*n!=int((2*n)**0.5)*(int((2*n)**0.5)+1):
        print("No")
        exit()
    print("Yes")
    l=int((2*n)**0.5)
    print(l+1)
    work=[[] for _ in range(l+1)]
    now_sub=0
    next_sub=1
    for i in range(1,n+1):
        if len(work[now_sub])==l:
            now_sub+=1
            next_sub=now_sub+1
        work[now_sub].append(i)
        work[next_sub].append(i)
        next_sub+=1
    
    for i in range(l+1):
        print("{} {}".format(l," ".join(map(str,work[i]))))

main()
