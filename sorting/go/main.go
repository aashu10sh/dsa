package main

import (
	"fmt"
	"sync"
)

func main() {
	var wg sync.WaitGroup

	// fmt.Println("Insertion Sort")
	go selection_sort()
	wg.Add(1)
	go insertion_sort()
	wg.Add(2)
	// fmt.Println("Selection Sort")
	wg.Wait()

}

func insertion_sort() {
	array := [6]int{6, 1, 3, 2, 4, 5}
	fmt.Println("[i] The Unsorted Array is ", array)
	for i := 1; i < len(array); i++ {
		x := array[i]
		j := i - 1
		for j >= 0 && array[j] > x {
			array[j+1] = array[j]
			j--
		}
		array[j+1] = x
	}
	fmt.Println("[i] The Sorted Array is ", array)
}

func selection_sort() {
	array := [6]int{6, 5, 4, 3, 2, 1}
	fmt.Println("[s] The Unsorted Array is ", array)
	for i := 0; i < len(array); i++ {
		minimum := array[i]
		for j := i + 1; j < len(array); j++ {
			if array[j] < minimum {
				array[i] = array[j]
				// array[j] = minimum
			}
			array[i] = array[j]
		}
	}
	fmt.Println("The Sorted Array is ", array)

}
