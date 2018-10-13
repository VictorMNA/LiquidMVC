// TODO: add header    

#ifndef MENUOPTION_H
#define MENUOPTION_H  

#include <limits.h>

typedef void (*CallbackFunction)(void);

class MenuOption
{
  public:
   
    enum class Type
    {
      NONE,
      INT_VALUE,
      ACTION,
      SUBMENU
    };

    MenuOption(String name, Type type = Type::NONE):
    _name(name),
    _type(type)
    {
    }    
  
    String getName(void)
    {
      return _name;
    }

    Type getType(void)
    {
      return _type;
    }
    
    String getTypeName(void)
    {
      switch(_type)
      {
        case Type::INT_VALUE:
          return "Int value type";
          break;
                
        case Type::ACTION:
          return "Action type";
          break;
                
        case Type::SUBMENU:
          return "Submenu type";
          break;
          
        case Type::NONE:
        default:
          return "No type detected";
          break;      
      }
    }

  private:
    const String  _name;
    const Type _type;
};

class MenuOptionIntValue: public MenuOption
{
  public:
    MenuOptionIntValue(String name, int& value, int min = INT_MIN, int max = INT_MAX):
    MenuOption(name, Type::INT_VALUE),
    _value(value),
    _minValue(min),
    _maxValue(max),
    _valueChanged(NULL)
    {
    }

    int getValue(void)
    {
      return _value;
    }

    void NextValue(void)
    {
      if(_value < _maxValue)
      {
        _value++;
        if(_valueChanged != NULL)
        {
          _valueChanged();
        }
      }
    }

    void PrevValue(void)
    {
      if(_value > _minValue)
      {
        _value--;
        if(_valueChanged != NULL)
        {
          _valueChanged();
        }
      }
    }

    void setValueChangedCallback(CallbackFunction function)
    {
      _valueChanged = function;
    }

    private:
      int& _value;
      int _minValue;
      int _maxValue;
      CallbackFunction _valueChanged;
};

class MenuOptionAction: public MenuOption
{
  public:
    MenuOptionAction(String name, CallbackFunction function):
    MenuOption(name, Type::ACTION),
    _function(function)
    {
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
    MenuOption(name, Type::SUBMENU)
    {
    }  
};


#endif
