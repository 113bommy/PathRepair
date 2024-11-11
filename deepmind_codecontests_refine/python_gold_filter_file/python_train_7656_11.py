n = int(input())
string = input()
numbers = sorted(set(map(int, string.split())))
results = "NO"
if len(numbers) < 3:
    results = "YES"
elif len(numbers) == 3 and numbers[2] - numbers[1] == numbers[1] - numbers[0]:
    results = "YES"
print(results)