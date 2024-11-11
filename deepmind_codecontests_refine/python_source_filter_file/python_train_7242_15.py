string = input()
a = list((string.count("B"), string.count("u")//2, string.count("l"), string.count("b"), string.count("a")//2,
         string.count("z"), string.count("r")))
print(min(a))