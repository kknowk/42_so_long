# プロジェクトタイトル

42_so_long

## 概要

minilibx を使用した小さな 2D ゲームです。
可愛いドット絵が見れるかも。

## 動機

42Tokyoの課題であり、また、  
テクスチャ、スプライト、タイルについて学び  
以前の課題で作成したlibft.a、 ft_printf、 get_next_lineのライブラリを活用し  
パス探索アルゴリズムを用い適切なエラー管理の元、実装できるよう作成しました。

## 使用方法

> - **normal**
> ```bash php
> #!/bin/bash
> cd 42_so_long
> make
> ./so_long maps/simple_map.ber
> ```

mapが起動し、ゲームが遊べるようになります。

## 操作方法

> - **key操作**  
> W ↑（上移動）  
> A ←（左移動)  
> S ↓（下移動）  
> D →（右移動）

> - **終わり方**  
> 画面上で終わる（中断）にはescもしくは左上の赤❌を押してください。  
> ターミナル上で終わる（中断）にはシグナルを送り、ループを抜けてください。（mac だと control C）  
> 全てのアイテム（宝箱）を取ってからゴール（さくらんぼ）に到達。

> - **ターミナルの出力**  
> ターミナルには現在の歩数が出されます。  
> 最短歩数を目指しましょう！

## 技術スタック

C言語
minilibx
