a, b = [int('14' if x == '1' else x) for x in input().split()
print('Alice' if a > b else 'Bob' if b > a else 'Draw')