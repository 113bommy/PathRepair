n, m, k = map(int, input().split())
array = list(map(int, input().split()))
a = max(array)
array.remove(a)
b = max(array)
s = (m//(k+1)) * a * k + b*m//(k+1) +  (m%(k+1)) * a
print(s)