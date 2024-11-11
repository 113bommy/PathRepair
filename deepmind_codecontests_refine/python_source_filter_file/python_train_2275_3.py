n = int(input())
*a, = map(int, input().split())
print("No" if len(list(filter(lambda x: x%2, a)))%2 else "Yes")
