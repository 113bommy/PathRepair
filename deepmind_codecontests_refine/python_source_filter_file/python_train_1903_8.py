for _ in range(int(input())):
    n = int(input())
    o_arr = list(map(int,input().split()))
    l = list(map(int,input().split()))
    ans = []
    for i in range(n):
        if l[i]==0:
    	    ans.append(o_arr[i])
    ans.sort(reverse=True)
    i = 0
    for j in range(n):
        if l[i]==0:
            o_arr[j]=ans[i]
            i+=1
    print(*o_arr)