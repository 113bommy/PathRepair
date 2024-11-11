import collections

def resolve():
  N = int(input())
  StrageList = [int(x) for x in input().split(" ")]
  collectionsStrage = collections.Counter(StrageList)

  events = int(input())

  two = 0
  four = 0
  six = 0
  eight = 0

  for planks in collectionsStrage:
    if collectionsStrage[planks] == 2 or collectionsStrage[planks] == 3:
      two += 1
    elif collectionsStrage[planks] == 4 or collectionsStrage[planks] == 5:
      four += 1
    elif collectionsStrage[planks] == 6 or collectionsStrage[planks] == 7:
      six += 1
    elif collectionsStrage[planks] >= 8:
      eight += 1

  for _ in range(events):
    inout = input().split(" ")
    if inout[0] == "+":
      collectionsStrage[int(inout[1])] += 1
      if collectionsStrage[int(inout[1])] == 2:
        two += 1
      elif collectionsStrage[int(inout[1])] == 4:
        two -= 1
        four += 1
      elif collectionsStrage[int(inout[1])] == 6:
        four -= 1
        six += 1
      elif collectionsStrage[int(inout[1])] == 8:
        six -= 1
        eight += 1
    else:
      collectionsStrage[int(inout[1])] -= 1
      if collectionsStrage[int(inout[1])] == 1:
        two -= 1
      elif collectionsStrage[int(inout[1])] == 3:
        two += 1
        four -= 1
      elif collectionsStrage[int(inout[1])] == 5:
        four += 1
        six -= 1
      elif collectionsStrage[int(inout[1])] == 7:
        six += 1
        eight -= 1

    if (eight >= 1) or (two >= 1 and six >= 1) or (two >= 2 and four >= 1) or (four >= 2 and six >= 1) or (six >= 2) or (four >= 2):
      print("YES")
    else:
      print("NO")

if __name__ == "__main__":
  resolve()
