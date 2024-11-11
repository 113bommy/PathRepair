N = int(input())
a = sorted(map(int, input().split()))
print( "Yes" if np.sum(a[:-1]) > a[-1] else "No" )