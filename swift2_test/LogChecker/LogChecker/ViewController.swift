//
//  ViewController.swift
//  LogChecker
//
//  Created by kyan shouya on 2016/12/23.
//  Copyright © 2016年 mycompany. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func PushNext(sender: AnyObject) {
    }


    
    class ViewController: UIViewController {
        
        @IBOutlet weak var scview: UIScrollView! //storyboardでスクロールビューを配置しているので接続
        
        override func viewDidLoad() {
            super.viewDidLoad()
            
            let graphview = Graph() //グラフを表示するクラス
            scview.addSubview(graphview) //グラフをスクロールビューに配置
            graphview.drawLineGraph() //グラフ描画開始
            
            scview.contentSize = CGSize(width:graphview.checkWidth()+20, height:graphview.checkHeight()) //スクロールビュー内のコンテンツサイズ設定
        }
        
    }
}

