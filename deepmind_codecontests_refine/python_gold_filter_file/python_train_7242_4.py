from collections import Counter

if __name__ == "__main__":
    inpstr = input().strip()
    
    counter = Counter()

    result = 100000
    for x in inpstr:
        if x in list("Bulbasr"):
            counter[x] += 1

    result = min(result, counter["B"])
    result = min(result, counter["u"]//2)
    result = min(result, counter["b"])
    result = min(result, counter["a"]//2)
    result = min(result, counter["l"])
    result = min(result, counter["s"])
    result = min(result, counter["r"])

    print(result)


    
