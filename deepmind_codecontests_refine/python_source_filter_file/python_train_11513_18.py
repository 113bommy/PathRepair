n,k=map(int,input().split())
a=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
l=[a[i%k]for i in range(n)]
print(*l)