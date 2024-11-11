a,b,k=map(int,input().split())
if k > b-a:
    k = -(b-a)//2*-1
print('\n'.join(map(str,sorted(set(range(a,a+k)) | set(range(b-k+1,b+1))))))