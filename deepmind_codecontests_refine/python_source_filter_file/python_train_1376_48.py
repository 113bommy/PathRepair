cases = int(input())

for each in range(cases):
    data = str(input())
    split_data = data.split("_")
    suffix = split_data[-1]
    # print(suffix)
    if "po" in suffix:
        print("FILIPINO")
    elif "mnida" in suffix:
        print("KOREAN")
    else:
        print("JAPANESE")