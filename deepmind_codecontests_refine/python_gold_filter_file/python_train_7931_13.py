num_queries = int(input())

for _ in range(num_queries):
    _ = int(input())

    skills = sorted(set(map(int, input().split())))
    for i, skill in enumerate(skills[:-1]):
        if skill + 1 == skills[i + 1]:
            print(2)
            break
    else:
        print(1)
