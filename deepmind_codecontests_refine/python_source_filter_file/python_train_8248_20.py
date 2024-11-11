def main():
    test=int(input())
    for _ in range(test):
        n=int(input())
        s=list(map(int,input().split()))
        s.sort()
        ans=-1
        for var in range(1,1023):
            current=[]
            for index in range(n):
                current.append(var^ s[index])
            current.sort()
            for index in range(n):
                if current[index]!=s[index]:
                    break
            else:
                ans=var
                break
        print(ans)

main()