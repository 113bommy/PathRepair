input()
list_ = [n % 2 for n in map(int, input().rstrip("\n").split())]

print("YES" if list_.count(1) % 2 else "NO")