# http://codeforces.com/problemset/problem/1294/B


for _ in range(int(input())):
    n = int(input())
    pkg = []
    for i in range(n):
        (x,y) = [int(x) for x in input().split()]
        pkg.append((x,y))
    pkg.sort()
    flag = True
    ans = []
    ans.append(pkg[0][0])
    ans.append((pkg[0][1])*(-1))
    for i in range(n-1):
        if(pkg[i][0]>pkg[i+1][0]):
            flag = False
            break
        elif(pkg[i][0]==pkg[i+1][0]):
            if(pkg[i][1]>pkg[i+1][1]):
                flag = False
                break
            else:
                k = (pkg[i+1][1]-pkg[i][1])*(-1)
                ans.append(k)
        else:
            if(pkg[i][1]>pkg[i+1][1]):
                flag = False
                break
            k = (pkg[i+1][0]-pkg[i][0])*(1)
            ans.append(k)
            k = (pkg[i+1][1]-pkg[i][1])*(-1)
            ans.append(k)

    if(flag):
        print("YES")
        print(len(ans))
        for i in range(len(ans)-1):
            if(ans[i]>0):
                print("R"*ans[i],end="")
            elif(ans[i]<0):
                print("U"*abs(ans[i]),end="")
        k = ans[-1]
        if(k>0):
            print("R"*k)
        else:
            print("U"*abs(k))
    else:
        print("NO")