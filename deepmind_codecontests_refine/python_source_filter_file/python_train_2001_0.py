def main():
    n = int(input())
    s = input()
    lst = ['a']*n
    ans=''
    m=0
    for i in range(n):
        for j in range(n):
            if lst[j]<=s[i]:
                lst[j] = s[i]
                ans+=str(j+1)
                m = max(m, j+1)
                break
    print (m)
    print (*ans)
main()

