#include "AClickableGameObject.hpp"

namespace rhythm
{
	AClickableGameObject::AClickableGameObject(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color) noexcept
		: AGameObject(position, size, color), _isSelected(false)
	{ }

	void AClickableGameObject::InvokeEvent(const sf::Event& event) noexcept
	{
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			auto size = GetSize();
			auto pos = GetPosition();
			int mouseX = event.mouseButton.x;
			int mouseY = event.mouseButton.y;
			int sizeX = static_cast<int>(size.x);
			int sizeY = static_cast<int>(size.y);
			int posX = static_cast<int>(pos.x);
			int posY = static_cast<int>(pos.y);
			if (mouseX > posX && mouseX < posX + sizeX
			&& mouseY > posY && mouseY < posY + sizeY)
			{
				if (!_isSelected)
				{
					_isSelected = true;
					OnSelect();
				}
				OnClick(sf::Vector2i(event.mouseButton.x - posX, event.mouseButton.y - posY));
			}
			else if (_isSelected)
			{
				_isSelected = false;
				OnUnselect();
			}
		}
	}

	void AClickableGameObject::Click() noexcept
	{
		OnSelect();
		OnClick(sf::Vector2i(0, 0));
	}

	void AClickableGameObject::OnSelect() noexcept { }
	void AClickableGameObject::OnUnselect() noexcept { }
	void AClickableGameObject::OnClick(const sf::Vector2i&) noexcept { }
}