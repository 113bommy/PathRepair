N = int(raw_input())
list_input = sorted(map(int, raw_input().split()))
print(sum(list_input[::2]))