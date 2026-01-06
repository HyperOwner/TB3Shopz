local Rayfield = loadstring(game:HttpGet('https://sirius.menu/rayfield'))()
local executor = identifyexecutor and identifyexecutor() or "Unknown Executor"

local customTheme = {
   TextColor = Color3.fromRGB(0, 255, 0),
   Background = Color3.fromRGB(10, 10, 10),
   Topbar = Color3.fromRGB(0, 0, 0),
   Shadow = Color3.fromRGB(30, 30, 30),
   NotificationBackground = Color3.fromRGB(15, 15, 15),
   NotificationActionsBackground = Color3.fromRGB(20, 20, 20),
   TabBackground = Color3.fromRGB(10, 10, 10),
   TabStroke = Color3.fromRGB(0, 255, 0),
   TabBackgroundSelected = Color3.fromRGB(20, 20, 20),
   TabTextColor = Color3.fromRGB(100, 255, 100),
   SelectedTabTextColor = Color3.fromRGB(0, 255, 0),
   ElementBackground = Color3.fromRGB(15, 15, 15),
   ElementBackgroundHover = Color3.fromRGB(25, 25, 25),
   SecondaryElementBackground = Color3.fromRGB(20, 20, 20),
   ElementStroke = Color3.fromRGB(0, 255, 0),
   SecondaryElementStroke = Color3.fromRGB(0, 255, 0),
   SliderBackground = Color3.fromRGB(30, 30, 30),
   SliderProgress = Color3.fromRGB(0, 255, 0),
   SliderStroke = Color3.fromRGB(0, 255, 0),
   ToggleBackground = Color3.fromRGB(25, 25, 25),
   ToggleEnabled = Color3.fromRGB(0, 255, 0),
   ToggleDisabled = Color3.fromRGB(80, 80, 80),
   ToggleEnabledStroke = Color3.fromRGB(0, 255, 0),
   ToggleDisabledStroke = Color3.fromRGB(80, 80, 80),
   ToggleEnabledOuterStroke = Color3.fromRGB(0, 255, 0),
   ToggleDisabledOuterStroke = Color3.fromRGB(50, 50, 50),
   DropdownSelected = Color3.fromRGB(30, 30, 30),
   DropdownUnselected = Color3.fromRGB(20, 20, 20),
   InputBackground = Color3.fromRGB(10, 10, 10),
   InputStroke = Color3.fromRGB(0, 255, 0),
   PlaceholderColor = Color3.fromRGB(0, 255, 0),
   KeyInputBackground = Color3.fromRGB(10, 10, 10),
   KeyInputTextColor = Color3.fromRGB(0, 255, 0)
}

local Window = Rayfield:CreateWindow({
   Name = "X-Dk V2 | Tha Bronx | " .. executor,
   Icon = nil,
   LoadingTitle = "",
   LoadingSubtitle = "",
   Theme = customTheme,
   DisableRayfieldPrompts = false,
   DisableBuildWarnings = false,
   ConfigurationSaving = {
      Enabled = false,
      FolderName = "GreenBlackThemeHub",
      FileName = "BigHub"
   },
   Discord = {
      Enabled = false,
      Invite = "",
      RememberJoins = true
   },
   KeySystem = false,
   KeySettings = {
      Title = "",
      Subtitle = "Authentication Required",
      Note = "Get your key at: discord.gg/dkshub",
      FileName = "jc_hub_key",
      SaveKey = true,
      GrabKeyFromSite = false,
      Key = {""},
      Theme = customTheme
   }
})

local MainTab = Window:CreateTab("Main", 4483362458)
local MainSection1 = MainTab:CreateSection("Welcome!")

local Paragraph1 = MainTab:CreateParagraph({Title = "Welcome!", Content = "Thank you for using X-Dk."})

local MainSection2 = MainTab:CreateSection("User Information")

local player = game.Players.LocalPlayer
local username = player.Name
MainTab:CreateLabel("Player: " .. username)

local userId = player.UserId
MainTab:CreateLabel("User Id: " .. userId)

local MainSection3 = MainTab:CreateSection("Game and Executor")

local gameName = game:GetService("MarketplaceService"):GetProductInfo(game.PlaceId).Name
MainTab:CreateLabel("Game: " .. gameName)

local executor = identifyexecutor and identifyexecutor() or "Unknown Executor"
MainTab:CreateLabel("Executor: " .. executor)

MainTab:CreateSection("Hardware")

local function getHWID()
    if syn and syn.request then
        return syn.crypt and syn.crypt.hash or "Synapse HWID Unavailable"
    elseif identifyexecutor and identifyexecutor():lower():find("scriptware") then
        return "ScriptWare HWID is not publicly accessible"
    elseif gethwid then
        return gethwid()
    elseif fluxus and fluxus.gethwid then
        return fluxus.gethwid()
    elseif isexecutorenv and isexecutorenv() then
        return getgenv().KRNL_ID or "KRNL HWID Unavailable"
    end
    return "HWID Not Supported"
end

local hwid = getHWID()
MainTab:CreateLabel("HWID: " .. hwid)

MainTab:CreateSection("Date + Time")

local currentDate = os.date("%Y-%m-%d")
MainTab:CreateLabel("Date: " .. currentDate)

local currentTime = os.date("%H:%M:%S")
MainTab:CreateLabel("Time: " .. currentTime)

MainTab:CreateSection("Credits")

MainTab:CreateButton({
    Name = "Join Discord!", 
    Callback = function()
        if setclipboard then
            setclipboard("https://[Log in to view URL]")
            print("Copied to clipboard!")
        else
            print("Your executor does not support setclipboard.")
        end

        Rayfield:Notify({
            Title = "Link Copied!",
            Content = "The Discord link has been copied to your clipboard.",
            Duration = 8.5
        })
    end,
})

MainTab:CreateLabel("Credits: XDkdev | Read Bio before @")

local InfiniteMoneyTab = Window:CreateTab("Infinite Money", 4483362458) -- Title, Image
local InfiniteMoneySection = InfiniteMoneyTab:CreateSection("Main")

InfiniteMoneyTab:CreateLabel("Read Before Use: This does not work for Xeno Or Solara")

InfiniteMoneyTab:CreateButton({
    Name = "Infinite Money",
    Callback = function()
        print("Infinite Money button clicked!")

        local World = game.Workspace
        local SharedStorage = game.ReplicatedStorage
        local Player = game.Players.LocalPlayer
        local Rio = {}

        local function Notify(title, desc, time)
            Rayfield:Notify({
                Title = title,
                Content = desc,
                Duration = time or 5
            })
        end

        local function InvokeServer(Remote, ...)
            return Remote:InvokeServer(...)
        end

        local function FindItem(name)
            return Player.Backpack:FindFirstChild(name) or Player.Character and Player.Character:FindFirstChild(name)
        end

        local function GetValue(path)
            local val = Player:FindFirstChild("stored") and Player.stored:FindFirstChild(path)
            return val and val.Value or 0
        end

        local function Teleport(pos)
            if Player.Character and Player.Character:FindFirstChild("HumanoidRootPart") then
                Player.Character.HumanoidRootPart.CFrame = CFrame.new(pos)
            end
        end

        local function BuySupplies()
            local Items = { "Ice-Fruit Bag", "Ice-Fruit Cupz", "FijiWater", "FreshWater" }
            if not SharedStorage:FindFirstChild("ExoticStock") or not SharedStorage:FindFirstChild("ExoticShopRemote") then
                return false
            end

            for _, item in ipairs(Items) do
                local stock = SharedStorage.ExoticStock:FindFirstChild(item)
                if not stock or stock.Value == 0 then return false end
            end

            for _, item in ipairs(Items) do
                local success = pcall(function()
                    InvokeServer(SharedStorage.ExoticShopRemote, item)
                end)
                if not success then return false end
                task.wait(1.25)
            end

            for _, item in ipairs(Items) do
                if not FindItem(item) then return false end
            end
            return true
        end

        local function GetCookingPot()
            if not World:FindFirstChild("CookingPots") then return nil end
            for _, pot in ipairs(World.CookingPots:GetChildren()) do
                local owner = pot:FindFirstChild("Owner")
                local cook = pot:FindFirstChild("CookPart")
                local progress = cook and cook:FindFirstChild("Steam") and cook.Steam:FindFirstChild("LoadUI")
                if pot:IsA("Model") and owner and cook and progress and not owner.Value and not progress.Enabled then
                    return pot
                end
            end
            return nil
        end

        local function FakeExit()
            Notify("Infinite Money Failed", "This server has datastores GLITCHED. Please join a different server!", 10)
            task.wait(0.25)
            Rio.InfiniteMoney = false
        end

        -- Start process
        local money = GetValue("Money")
        if money < 2750 then
            Notify("WARNING", "Insufficient funds detected! You need at least 2750 to proceed.", 5)
            return
        end

        if not BuySupplies() then
            FakeExit()
            return
        end

        local CookingPot = GetCookingPot()
        if not CookingPot then
            FakeExit()
            return
        end

        local CookPart = CookingPot:FindFirstChild("CookPart")
        local CookPrompt = CookPart and CookPart:FindFirstChild("ProximityPrompt")
        local CookProgress = CookPart and CookPart:FindFirstChild("Steam") and CookPart.Steam:FindFirstChild("LoadUI")

        if not (CookPart and CookPrompt and CookProgress) then
            FakeExit()
            return
        end

        local FijiWater = FindItem("FijiWater")
        local FreshWater = FindItem("FreshWater")
        local IceFruitBag = FindItem("Ice-Fruit Bag")
        local IceFruitCupz = FindItem("Ice-Fruit Cupz")

        if not (FijiWater and FreshWater and IceFruitBag and IceFruitCupz) then
            FakeExit()
            return
        end

        local CookOrder = { FijiWater, FreshWater, IceFruitBag }

        Teleport(CookPart.Position)
        task.wait(0.25)

        local success, err = pcall(function()
            fireproximityprompt(CookPrompt, 0)
        end)
        if not success then
            print("Error: " .. err)
            FakeExit()
            return
        end
        task.wait(0.25)

        for _, item in ipairs(CookOrder) do
            Player.Character.Humanoid:EquipTool(item)
            task.wait(0.5)

            local success, err = pcall(function()
                fireproximityprompt(CookPrompt, 0)
            end)
            if not success then
                print("Error adding item: " .. err)
                FakeExit()
                return
            end
            task.wait(5)
        end

        while CookProgress.Enabled do
            task.wait(10)
        end

        Teleport(CookPart.Position)
        task.wait(0.25)

        Player.Character.Humanoid:EquipTool(IceFruitCupz)
        task.wait(0.1)

        local success, err = pcall(function()
            fireproximityprompt(CookPrompt, 0)
        end)
        if not success then
            print("Final cook error: " .. err)
            FakeExit()
            return
        end
        task.wait(1)

        local SellPart = World:FindFirstChild("IceFruit Sell")
        local SellPrompt = SellPart and SellPart:FindFirstChild("ProximityPrompt")
        if not (SellPart and SellPrompt) then
            FakeExit()
            return
        end

        Teleport(SellPart.Position)
        task.wait(0.25)

        for _ = 1, 2000 do
            local success, err = pcall(function()
                fireproximityprompt(SellPrompt, 0)
            end)
            if not success then
                print("Sell error: " .. err)
                FakeExit()
                return
            end
        end

        Notify("Success", "Infinite Money Finshed!", 5)
    end
})

    local ConstructionTab = Window:CreateTab("Construction", 4483362458)
ConstructionTab:CreateSection("Help")

local Paragraph3 = ConstructionTab:CreateParagraph({Title = "READ BEFORE USE", Content = "To use construction autofarm efficiently join a VC server using the button below VC server has no cooldown, unlike regular ones, so you won't need to wait 3 minutes after placing plywood, this lets you get max money in 10-15 minutes."})

ConstructionTab:CreateButton({
    Name = "Join VC Server",
    Callback = function()
        game:GetService("TeleportService"):Teleport(18642421777, game.Players.LocalPlayer)
    end,
})

ConstructionTab:CreateButton({
   Name = "Start Construction Job",
   Callback = function()
      local speaker = game:GetService("Players").LocalPlayer
      if not speaker then return end

      local function getCharacter()
         return speaker.Character or speaker.CharacterAdded:Wait()
      end

      local function fireProximityPrompt(prompt)
         if prompt and prompt:IsA("ProximityPrompt") then
            fireproximityprompt(prompt)
         end
      end

      local char = getCharacter()
      char:SetPrimaryPartCFrame(CFrame.new(-1728, 371, -1172))
      task.wait(0.2)
      fireProximityPrompt(workspace.ConstructionStuff["Start Job"]:FindFirstChildOfClass("ProximityPrompt"))
      task.wait(0.5)
   end,
})

ConstructionTab:CreateSection("Construction Autofarm")

local Paragraph2 = ConstructionTab:CreateParagraph({Title = "Note", Content = "if you experience the error where it does not equip plywood, please reexecute the script and try again."})

local autofarmRunning = false

ConstructionTab:CreateToggle({
   Name = "Enable Construction Autofarm",
   CurrentValue = false,
   Flag = "ConstructionFarmFlag",
   Callback = function(Value)
      autofarmRunning = Value
      local speaker = game:GetService("Players").LocalPlayer
      if not speaker then return end

      local function getCharacter()
         return speaker.Character or speaker.CharacterAdded:Wait()
      end

      local function getBackpack()
         return speaker:FindFirstChild("Backpack")
      end

      local function hasPlyWood()
         local backpack = getBackpack()
         local character = getCharacter()
         return (backpack and backpack:FindFirstChild("PlyWood")) or (character and character:FindFirstChild("PlyWood"))
      end

      local function equipPlyWood()
         local backpack = getBackpack()
         if backpack then
            local plyWood = backpack:FindFirstChild("PlyWood")
            if plyWood then
               plyWood.Parent = getCharacter()
            end
         end
      end

      local function fireProximityPrompt(prompt)
         if prompt and prompt:IsA("ProximityPrompt") then
            fireproximityprompt(prompt)
         end
      end

      local function grabWood()
         getCharacter():SetPrimaryPartCFrame(CFrame.new(-1727, 371, -1178))
         task.wait(0.1)

         while autofarmRunning and not hasPlyWood() do
            fireProximityPrompt(workspace.ConstructionStuff["Grab Wood"]:FindFirstChildOfClass("ProximityPrompt"))
            task.wait(0.1)
            equipPlyWood()
         end
      end

      local function buildWall(wallPromptName, wallPosition)
         local prompt = workspace.ConstructionStuff[wallPromptName]:FindFirstChildOfClass("ProximityPrompt")

         while autofarmRunning and prompt and prompt.Enabled do
            getCharacter():SetPrimaryPartCFrame(wallPosition)
            task.wait(0.01)
            fireProximityPrompt(prompt)
            task.wait()
            if not hasPlyWood() then
               grabWood()
            end
         end
      end

      if autofarmRunning then
         task.spawn(function()
            while autofarmRunning do
               if not hasPlyWood() then
                  grabWood()
               end

               buildWall("Wall2 Prompt", CFrame.new(-1705, 368, -1151))
               buildWall("Wall3 Prompt", CFrame.new(-1732, 368, -1152))
               buildWall("Wall4 Prompt2", CFrame.new(-1772, 368, -1152))
               buildWall("Wall1 Prompt3", CFrame.new(-1674, 368, -1166))

               task.wait(0.1)
            end
         end)
      end
   end
})
