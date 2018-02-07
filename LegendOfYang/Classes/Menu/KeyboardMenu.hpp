//
//  KeyboardMenu.hpp
//  LegendOfYang
//
//  Created by John Rehbein on 2/4/18.
//

#pragma once

USING_NS_CC;

// Class Description - This class displays a vertical box of options you can select
// Use Cases - Action Selecting during a battle, Selecting Save file, Selecting Item from inventory, etc.

/* ExampleCode -
 std::vector<LabelAndCallback> items;
 LabelAndCallback item1, item2;
 item1.first = "Option 1";
 item2.first = "Option 2";
 item1.second = CC_CALLBACK_1(MyClassName::callBackFunction1, this);
 item2.second = CC_CALLBACK_1(MyClassName::callBackFunction2, this);
 items.push_back(item1);
 items.push_back(item2);
 auto menu = KeyboardMenu::create(items);
 guiNode->addChild(menu);
 
 // Somewhere in your class
 void MyClassName::callBackFunction1(Node *keyboardMenu) {
     // Handle callback 1
 }
 void MyClassName::callBackFunction2(Node *keyboardMenu) {
     // Handle callback 2
 }
 */

typedef std::pair<std::string, std::function<void(Node*)>> LabelAndCallback;

class KeyboardMenu : public Node {
public:
    // Interface functions
    std::string selectedLabelText() { return _items.at(selectedItem).first; };
    void setContentSize(const cocos2d::Size &contentSize) override;
    
    // Initialization functions
    virtual bool init() override;
    CREATE_FUNC(KeyboardMenu);
    static KeyboardMenu* create(const std::vector<LabelAndCallback> &items);
    static KeyboardMenu* create(const std::vector<LabelAndCallback> &items, const Size &contentSize);
    
protected:
    void onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event);
    void updateDisplay();
    int selectedItem;
    std::vector<LabelAndCallback> _items;
    
};
