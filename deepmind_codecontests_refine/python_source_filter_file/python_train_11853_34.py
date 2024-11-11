h, w = map(int, input().split())
a = ["#"*(w+2)] + ["#" + input() + "#" for i in h] + ["#"*(w+2)]
for s in a:
  print(s)

