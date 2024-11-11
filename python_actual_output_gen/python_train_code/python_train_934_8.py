print(max(map(lambda w: len(list(filter(str.isupper, w))), input().split(' '))))
