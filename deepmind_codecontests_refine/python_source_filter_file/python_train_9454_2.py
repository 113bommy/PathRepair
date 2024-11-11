def main():
    n=int(input())
    for k in range(1,450):
        if k*(k+1)==2*n:
            print("Yes")
            print(k+1)
            break
    else:
        print("No")
        return 0
    ans=[]
    cnt=0
    for i in range(k+1):
        ans.append([])
        for j in range(i):
            ans[i].append(ans[j][i-1])
        for j in range(i,k):
            ans[i].append(cnt)
            cnt+=1
    for i in ans:
        print(len(i),*i)
main()