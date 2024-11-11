number_of_juices = int(input())
percents = list(map(lambda p: int(p), input().split()))

result = 1/(number_of_juices)*sum(percents)

print(result)