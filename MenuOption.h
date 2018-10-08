// TODO: add header    

#ifndef MENUOPTION_H
#define MENUOPTION_H  

  
class MenuOption
{
  public:
   
    enum class MenuType
    {
      MENU_NONE,
      MENU_INT_VALUE,
      MENU_ACTION,
      MENU_SUBMENU
    };

    MenuOption(String name, MenuType type = MenuType::MENU_NONE):
    _name(name),
    _type(type)
    {
    }    
  
    String getName(void)
    {
      return _name;
    }

    MenuType getType(void)
    {
      return _type;
    }
    
    String getTypeName(void)
    {
      switch(_type)
      {
        case MenuType::MENU_INT_VALUE:
          return "Int value type";
          break;
                
        case MenuType::MENU_ACTION:
          return "Action type";
          break;
                
        case MenuType::MENU_SUBMENU:
          return "Submenu type";
          break;
          
        case MenuType::MENU_NONE:
        default:
          return "No type detected";
          break;      
      }
    }

  private:
    String  _name;
    MenuType _type;
};

class MenuOptionIntValue: public MenuOption
{
  public:
    MenuOptionIntValue(String name, int* value):
    MenuOption(name, MenuType::MENU_INT_VALUE)
    {
      _value = value;
    }

    int getValue(void)
    {
      return *_value;
    }

    void NextValue(void)
    {
      (*_value)++;
    }

    void PrevValue(void)
    {
      (*_value)--;
    }

    private:
      int* _value;
};

typedef void (*CallbackFunction)(void);
class MenuOptionAction: public MenuOption
{
  public:
    MenuOptionAction(String name, CallbackFunction function):
    MenuOption(name, MenuType::MENU_ACTION)
    {
      _function = function;
    }

    void ExecuteCallback(void)
    {
      if(_function != NULL)
      {
        _function();
      }
    }

  private:
    CallbackFunction _function;
};


// TODO: implement behaviour
class MenuOptionSubmenu: public MenuOption
{
  public:
    MenuOptionSubmenu(String name):
    MenuOption(name, MenuType::MENU_SUBMENU)
    {
    }  
};


#endif
