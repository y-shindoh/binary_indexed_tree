/* -*- coding: utf-8; tab-width: 4 -*- */
/**
 * @file	binary_indexed_tree.hpp
 * @brief	binary indexed treeのテンプレート
 * @author	Yasutaka SHINDOH / 新堂 安孝
 * @note	http://anctgcc.hatenablog.com/entry/2014/12/03/194140 を参考に実装した。
 */

#include <cstddef>
#include <cassert>
#include <vector>

namespace ys
{
	/**
	 * @class	binary inde treeのテンプレート・クラス
	 */
	template<typename TYPE>
	class BinaryIndexedTree
	{
	private:

		std::vector<TYPE> data_;	///< BIT本体

		void
		add(size_t i,
			TYPE v)
			{
				if (!i) return;

				const size_t l(data_.size());

				while (i < l) {
					data_[i] += v;		// 該当パスに加算
					i += i & (~i + 1);	// i の最下位の桁を繰り上げ
				}
			}

		TYPE
		get(size_t i) const
			{
				TYPE v((TYPE)0);

				while (i) {
					v += data_[i];	// 部分パスを加算
					i &= i - 1;		// i の最下位ビットを0に変更
				}

				return v;
			}

	public:

		/**
		 * コンストラクタ
		 */
		BinaryIndexedTree()
			{
				;
			}

		/**
		 * BTIの構築
		 * @param[in]	data	各エッジのコストの配列
		 * @param[in]	length	引数 @a data の長さ
		 * @note	引数 @a data は各エッジの終点ノードをインデックスと考える。
		 */
		void
		prepare(const TYPE* data,
				size_t length)
			{
				data_.resize(length);

				for (size_t i(0); i < length; ++i) {
					data_[i] = (TYPE)0;
				}

				for (size_t i(0); i < length; ++i) {
					add(i, data[i]);
				}
			}

		/**
		 * パス (連続するエッジをつなげたもの) の総コスト
		 * @param[in]	from	最初のエッジの始点ノード
		 * @param[in]	to	最後のエッジの終点ノード
		 * @return	総コスト
		 * @note	本メソッド実施前に @a prepare() を実行すること。
		 */
		TYPE
		sum(size_t from,
			size_t to) const
			{
				assert(from <= to);
				assert(from < data_.size());
				assert(to < data_.size());

				return get(to) - get(from);
			}
	};
};
