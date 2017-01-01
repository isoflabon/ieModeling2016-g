//
//  ViewController.swift
//  AnimalFortune
//
//  Created by kyan shouya on 2016/12/03.
//  Copyright © 2016年 mycompany. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var animalLabel: UILabel!
    @IBOutlet weak var resultLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func tellFortunes(sender: AnyObject) {
        
        let random = arc4random_uniform(100)  //0~99
        
        switch random {
        case 0..<10:
            animalLabel.text = "🐶"
            resultLabel.text = "いぬ"
            
        case 10..<30:
            animalLabel.text = "😸"
            resultLabel.text = "ねこ"

        case 30..<50:
            animalLabel.text = "🐴"
            resultLabel.text = "うま"

        case 50..<70:
            animalLabel.text = "🐓"
            resultLabel.text = "にわとり"

        case 75..<95:
            animalLabel.text = "🐥"
            resultLabel.text = "ひよこ"
            
        default :
            animalLabel.text = "📱"
            resultLabel.text = "けいたい"

        }
        
    }

}

