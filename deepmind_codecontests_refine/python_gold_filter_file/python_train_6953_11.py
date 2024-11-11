all = [i * j for i in range(1, 10) for j in range(1, 10)]

print(["No", "Yes"][int(input()) in all])