print((lambda n: sum(sorted(map(int, input().split()), reverse=True)[1:n+1]))(int(input())))
