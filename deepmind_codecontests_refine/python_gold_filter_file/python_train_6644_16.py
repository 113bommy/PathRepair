def f(x):
    return x%10+f(x//10) if x else 0
n = int(input())
print(min([f(i)+f(n-i) for i in range(1,n)]))