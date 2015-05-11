/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	main.cpp
 * @brief	binary_indexed_tree.hppの動作確認用コマンド
 * @author	Yasutaka SHINDOH / 新堂 安孝
 */

#include <cstdio>
#include "binary_indexed_tree.hpp"

template<typename TYPE>
void print(char from,
		   char to,
		   ys::BinaryIndexedTree<TYPE>* bit)
{
	size_t i = (size_t)(from - 'A');
	size_t j = (size_t)(to - 'A');

	std::printf("[%c->%c]\t%d\n", from, to, bit->sum(i, j));
}

int main()
{
	int data[] = {0, 118, 191, 410, 598, 129, 493, 334, 357, 432};

	ys::BinaryIndexedTree<int>* bit = new ys::BinaryIndexedTree<int>();
	bit->prepare(data, sizeof(data) / sizeof(data[0]));

	char input[][2] = {{'A', 'B'}, {'A', 'C'}, {'C', 'D'}, {'A', 'E'}, {'E', 'F'},
					   {'E', 'G'}, {'G', 'H'}, {'A', 'I'}, {'I', 'J'}};

	for (size_t i(0); i < sizeof(input) / sizeof(input[0]); ++i) {
		print<int>(input[i][0], input[i][1], bit);
	}

	delete bit;

	return 0;
}
