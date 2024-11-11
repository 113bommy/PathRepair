for _ in range(int(input())):
    a,s=map(str,input().split())
    ans=""
    a=a.rjust(30,"0")
    s=s.rjust(30,"0")
    j=29

    for  i in range(29,-1,-1):
        if s[j]<a[i]:
            if (int(s[j-1:j+1])-int(a[i]))>9 or (int(s[j-1:j+1])-int(a[i]))<0:print(-1);break
            ans+=str(int(s[j-1:j+1])-int(a[i]))
            j-=2
        else:
            if (int(s[j])-int(a[i]))>9 or (int(s[j])-int(a[i]))<0:print(-1);break
            ans+=str((int(s[j])-int(a[i])))
            j-=1
    else:
        print(int(ans[29:9:-1]))