
t = int(input())
for x in range(t):
    new_str = ""
    long_of_str,\
    long_of_podstr,\
    podstr_set = map(int, input().split())
    for y in range(long_of_str):
        new_str += chr(y % podstr_set + 65)
    print(new_str)