
def __main__():
    part1 = part2 = 0
    input = open("input.txt", 'r')
    lines = input.read().splitlines()
    for line in lines:
        splitOnComma = line.split(',')
        nums = [x.split('-') for x in splitOnComma]
        sets = set(range(int(nums[0][0]), int(nums[0][1]) + 1)), set(range(int(nums[1][0]), int(nums[1][1]) + 1))
        if sets[0].issubset(sets[1]) or sets[0].issuperset(sets[1]):
            part1 += 1
        if sets[0] & sets[1]:
            part2 += 1

    print("Ex01: ", part1)
    print("Ex02: ", part2)


__main__()
