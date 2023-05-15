def bubble_sort(numbers):
    n = len(numbers)
    for i in range(n):
        # Zatrzymaj pętlę, jeśli żadne zamiany nie są już potrzebne
        already_sorted = True
        for j in range(n - i - 1):
            if numbers[j] > numbers[j + 1]:
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
                already_sorted = False
        if already_sorted:
            break
    return numbers


def quick_sort(numbers):
    if len(numbers) <= 1:
        return numbers
    pivot = numbers[len(numbers) // 2]
    left = [x for x in numbers if x < pivot]
    middle = [x for x in numbers if x == pivot]
    right = [x for x in numbers if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)
